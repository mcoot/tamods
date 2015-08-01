using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace TAModLauncher
{
    public class DLLInjector
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(int dwDesiredAccess, bool bInheritHandle, int dwProcessId);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern int CloseHandle(IntPtr hObject);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string lpModuleName);

        [DllImport("kernel32", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern IntPtr VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress,
            uint dwSize, uint flAllocationType, uint flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool WriteProcessMemory(IntPtr hProcess, IntPtr lpBaseAddress, byte[] lpBuffer, uint nSize, out UIntPtr lpNumberOfBytesWritten);

        [DllImport("kernel32.dll")]
        static extern IntPtr CreateRemoteThread(IntPtr hProcess,
            IntPtr lpThreadAttributes, IntPtr dwStackSize, IntPtr lpStartAddress, IntPtr lpParameter, uint dwCreationFlags, IntPtr lpThreadId);

        [DllImport("kernel32", SetLastError = true, ExactSpelling = true)]
        internal static extern Int32 WaitForSingleObject(IntPtr handle, Int32 milliseconds); 

        // privileges
        const int PROCESS_CREATE_THREAD = 0x0002;
        const int PROCESS_QUERY_INFORMATION = 0x0400;
        const int PROCESS_VM_OPERATION = 0x0008;
        const int PROCESS_VM_WRITE = 0x0020;
        const int PROCESS_VM_READ = 0x0010;

        // memory allocation
        const uint MEM_COMMIT = 0x00001000;
        const uint MEM_RESERVE = 0x00002000;
        const uint PAGE_READWRITE = 4;

        public string TargetProcessName { get; set; }
        public string DLLPath { get; set; }

        public DLLInjector(string processname, string dllpath)
        {
            TargetProcessName = processname;
            DLLPath = dllpath;
        }

        public bool DoesProcessExist(string processname)
        {
            return (Process.GetProcessesByName(processname).Length != 0);
        }

        public void Inject()
        {
            IntPtr processHandle = GetProcessHandle(TargetProcessName);
            IntPtr loadLibraryAddress = GetLoadLibraryAddress();
            IntPtr allocatedMemoryAddress = AllocateDLLNameMemory(processHandle, DLLPath);
            WriteDLLName(processHandle, allocatedMemoryAddress, DLLPath);
            
            // Create the thread to actually inject the DLL
            IntPtr injectedThread = CreateInjectedThread(processHandle, loadLibraryAddress, allocatedMemoryAddress);
            Int64 Result = WaitForSingleObject(injectedThread, 10 * 1000);
            if (Result == 0x00000080L || Result == 0x00000102L || Result == 0xFFFFFFFF)
            {
                throw new InjectorException("Injected thread failed to return.");
            }
            CloseHandle(processHandle);
        }

        private IntPtr GetProcessHandle(string processname)
        {
            // Fail if the target process does not exist
            if (!DoesProcessExist(processname))
            {
                throw new InjectorException("Process " + processname + " does not exist");
            }

            Process target = Process.GetProcessesByName(processname)[0];

            // Get the handle of the process with necessary privileges
            return OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, false, target.Id);
        }

        private IntPtr GetLoadLibraryAddress()
        {
            return GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
        }

        private IntPtr AllocateDLLNameMemory(IntPtr procHandle, string dllname)
        {
            // Allocate the required memory and get a pointer to its address
            return VirtualAllocEx(procHandle, IntPtr.Zero, (uint)((dllname.Length + 1) * Marshal.SizeOf(typeof(char))),
                        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        }

        private bool WriteDLLName(IntPtr procHandle, IntPtr memoryAddress, string dllname)
        {
            UIntPtr bytesWritten;

            return WriteProcessMemory(procHandle, memoryAddress, Encoding.Default.GetBytes(dllname), 
                    (uint)((dllname.Length + 1) * Marshal.SizeOf(typeof(char))), out bytesWritten);
        }

        private IntPtr CreateInjectedThread(IntPtr procHandle, IntPtr loadLibraryAddress, IntPtr memoryAddress)
        {
            return CreateRemoteThread(procHandle, IntPtr.Zero, IntPtr.Zero, loadLibraryAddress, memoryAddress, 0, IntPtr.Zero);
        }

        
    }

    public class InjectorException : Exception
    {
        public InjectorException() : base() { }

        public InjectorException(string message) : base(message) { }

        public InjectorException(string message, Exception inner) : base(message, inner) { }
    }
}
