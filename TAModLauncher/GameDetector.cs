using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Drawing;
using System.Diagnostics;

namespace TAModLauncher
{
    class GameDetector
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct RECT
        {
            public int left;
            public int top;
            public int right;
            public int bottom;
        }

        [DllImport("user32.dll")]
        private static extern bool GetWindowRect(HandleRef hWnd, [In, Out] ref RECT rect);

        [DllImport("user32.dll")]
        private static extern IntPtr GetForegroundWindow();

        [DllImport("user32.dll")]
        static extern uint GetWindowThreadProcessId(IntPtr hWnd, out int ProcessId);

        private int readyTime = 0;

        /// <summary>
        /// If true, the detector will automatically ready when the window is fullscreen,
        /// otherwise it will just use a straight timer
        /// </summary>
        public bool SmartMode { get; set; }

        /// <summary>
        /// The delay in seconds to wait after the process has launched
        /// </summary>
        public int Delay { get; set; }

        /// <summary>
        /// The process name to check for foreground status
        /// </summary>
        public string ProcessName { get; set; }

        public GameDetector(int delay, string processName, bool smartMode)
        {
            this.Delay = delay;
            this.ProcessName = processName;
            this.SmartMode = smartMode;
            Timer timer = new Timer();
            timer.Interval = 1000;
            timer.Tick += new EventHandler(Timer_tick);
            timer.Start();
        }

        /// <summary>
        /// Returns true if the process is ready for injection
        /// </summary>
        /// <returns>true iff the foreground window is ProcessName, and the delay has elapsed</returns>
        public bool IsReadyToInject()
        {
            return (readyTime >= Delay);
        }

        private void Timer_tick(object sender, EventArgs e)
        {
            if (!IsMyProcessInForeground() || (SmartMode && !IsForegroundFullscreen()))
            {
                // Only reset if not yet ready for inject
                if (readyTime < Delay) readyTime = 0;
            }
            else
            {
                if (readyTime < Delay)
                {
                    readyTime++;
                }
            }

        }

        /// <summary>
        /// Check whether the current foreground window on the given screen is fullscreen
        /// </summary>
        /// <param name="screen">the screen to check the foreground window for</param>
        /// <returns>true iff the screen's foreground window covers the whole screen</returns>
        private static bool IsForegroundFullscreen(Screen screen)
        {
            if (screen == null)
            {
                screen = Screen.PrimaryScreen;
            }

            RECT rect = new RECT();
            GetWindowRect(new HandleRef(null, GetForegroundWindow()), ref rect);

            return new Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top).Contains(screen.Bounds);
        }

        /// <summary>
        /// Check whether the current foreground window on the primary screen is fullscreen
        /// </summary>
        /// <returns>true iff the primary screen's foreground window covers the whole screen</returns>
        private static bool IsForegroundFullscreen()
        {
            return IsForegroundFullscreen(null);
        }

        /// <summary>
        /// Checks whether the given process is in the foreground
        /// </summary>
        /// <param name="process">the process to check</param>
        /// <returns>true iff the given process has a window in the foreground</returns>
        private static bool IsProcessInForeground(Process process)
        {
            IntPtr hWnd = GetForegroundWindow();
            if (hWnd == null) return false;

            int pid = process.Id;
            int foregroundpid;
            if (GetWindowThreadProcessId(hWnd, out foregroundpid) == 0) return false;

            return (foregroundpid == pid);
        }

        /// <summary>
        /// Checks whether any process with the given process name is in the foreground
        /// </summary>
        /// <param name="processName">the process name to check</param>
        /// <returns>true iff any process with the given name has a window in the foreground</returns>
        private static bool IsProcessByNameInForeground(string processName)
        {
            Process[] processes = Process.GetProcessesByName(processName);

            foreach (Process p in processes) {
                if (IsProcessInForeground(p)) return true;
            }

            return false;
        }

        /// <summary>
        /// Checks whether the GameDetector's process is in the foreground
        /// </summary>
        /// <returns>true iff any process with the GameDetector's process name has a window in the foreground</returns>
        private bool IsMyProcessInForeground()
        {
            return IsProcessByNameInForeground(ProcessName);
        }
    }
}
