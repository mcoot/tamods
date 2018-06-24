using System;
using System.ServiceProcess;
using System.IO;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace TAModConfigurationTool
{
    public class TransTabPage : TabPage
    {
        protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
        {

            e.Graphics.DrawImage(this.FindForm().BackgroundImage, -5, -33, 1267, 768);
        }
    }

    public class ColorSelector : Panel
    {
        // Controls
        private Label title;
        private NumericUpDown numR;
        private Label labelR;
        private NumericUpDown numG;
        private Label labelG;
        private NumericUpDown numB;
        private Label labelB;
        private NumericUpDown numA;
        private Label labelA;
        private PictureBox colorDisplay;
        private ColorDialog colorPicker;

        // The color represented 
        private Color color;

        // Events
        public event EventHandler ColorUpdated;

        public ColorSelector(string title, Color color)
            : base()
        {
            this.color = color;

            this.Size = new System.Drawing.Size(120, 170);

            initControls(title);
            initEventHandlers();
            updateColorUI();
        }

        public ColorSelector(Color color) : this("Colour", color) { }

        public ColorSelector(string title) : this(title, Color.FromArgb(255, 0, 0, 0)) { }

        public ColorSelector() : this("Colour", Color.FromArgb(255, 0, 0, 0)) { }

        private void initControls(string titletext)
        {

            Font ctrlFont = new Font("Segoe UI", 8.25F);

            // Construct Controls
            title = new Label();
            numR = new NumericUpDown();
            numG = new NumericUpDown();
            numB = new NumericUpDown();
            numA = new NumericUpDown();
            labelR = new Label();
            labelG = new Label();
            labelB = new Label();
            labelA = new Label();
            colorDisplay = new PictureBox();
            colorPicker = new ColorDialog();

            // Setup stupid fonts stupid stupid
            title.Font = new Font("Segoe UI", 9.75F, FontStyle.Bold);
            numR.Font = ctrlFont;
            numG.Font = ctrlFont;
            numB.Font = ctrlFont;
            numA.Font = ctrlFont;
            labelR.Font = ctrlFont;
            labelG.Font = ctrlFont;
            labelB.Font = ctrlFont;
            labelA.Font = ctrlFont;

            // Setup Controls
            title.Text = titletext;
            labelR.Text = "Red";
            labelR.AutoSize = false;
            labelR.TextAlign = ContentAlignment.MiddleLeft;
            labelG.Text = "Green";
            labelG.AutoSize = false;
            labelG.TextAlign = ContentAlignment.MiddleLeft;
            labelB.Text = "Blue";
            labelB.AutoSize = false;
            labelB.TextAlign = ContentAlignment.MiddleLeft;
            labelA.Text = "Alpha";
            labelA.AutoSize = false;
            labelA.TextAlign = ContentAlignment.MiddleLeft;

            numR.Width = 60;
            numR.AutoSize = false;
            numG.Width = 60;
            numG.AutoSize = false;
            numB.Width = 60;
            numB.AutoSize = false;
            numA.Width = 60;
            numA.AutoSize = false;

            numR.Minimum = 0;
            numG.Minimum = 0;
            numB.Minimum = 0;
            numA.Minimum = 0;
            numR.Maximum = 255;
            numG.Maximum = 255;
            numB.Maximum = 255;
            numA.Maximum = 255;

            colorDisplay.Size = new System.Drawing.Size(108, 20);
            colorDisplay.BackColor = Color.Black;
            colorDisplay.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;

            // Add Controls to Panel
            TableLayoutPanel t = new TableLayoutPanel();
            t.AutoSize = false;
            t.Size = this.Size;
            t.Location = new Point(0, 0);

            t.ColumnStyles.Clear();
            t.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 45F));
            t.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 60F));

            t.RowStyles.Clear();

            t.Controls.Add(title, 0, 0);
            t.SetColumnSpan(title, 2);
            t.Controls.Add(labelR, 0, 1);
            t.Controls.Add(numR, 1, 1);
            t.Controls.Add(labelG, 0, 2);
            t.Controls.Add(numG, 1, 2);
            t.Controls.Add(labelB, 0, 3);
            t.Controls.Add(numB, 1, 3);
            t.Controls.Add(labelA, 0, 4);
            t.Controls.Add(numA, 1, 4);
            t.Controls.Add(colorDisplay, 0, 5);
            t.SetColumnSpan(colorDisplay, 2);

            Controls.Add(t);
        }

        private void initEventHandlers()
        {
            numR.ValueChanged += new EventHandler(numColor_Changed);
            numG.ValueChanged += new EventHandler(numColor_Changed);
            numB.ValueChanged += new EventHandler(numColor_Changed);
            numA.ValueChanged += new EventHandler(numColor_Changed);

            colorDisplay.Click += new EventHandler(colorDisplay_Click);
            colorDisplay.MouseEnter += new EventHandler(colorDisplay_MouseEnter);
            colorDisplay.MouseLeave += new EventHandler(colorDisplay_MouseLeave);
        }

        private void removeEventHandlers()
        {
            numR.ValueChanged -= new EventHandler(numColor_Changed);
            numG.ValueChanged -= new EventHandler(numColor_Changed);
            numB.ValueChanged -= new EventHandler(numColor_Changed);
            numA.ValueChanged -= new EventHandler(numColor_Changed);

            colorDisplay.Click -= new EventHandler(colorDisplay_Click);
            colorDisplay.MouseEnter -= new EventHandler(colorDisplay_MouseEnter);
            colorDisplay.MouseLeave -= new EventHandler(colorDisplay_MouseLeave);
        }

        private void updateColorUI()
        {
            removeEventHandlers();
            numR.Value = color.R;
            numG.Value = color.G;
            numB.Value = color.B;
            numA.Value = color.A;

            colorDisplay.BackColor = color;
            colorPicker.Color = color;
            initEventHandlers();

            if (ColorUpdated != null)
            {
                ColorUpdated(this, EventArgs.Empty);
            }
        }

        public void setColor(Color color)
        {
            this.color = color;
            updateColorUI();
        }

        public void setColor(int r, int g, int b, int a)
        {
            setColor(Color.FromArgb(a, r, g, b));
        }

        public Color getColor()
        {
            return Color.FromArgb(color.A, color.R, color.G, color.B);
        }

        public void setTitle(string title)
        {
            this.title.Text = title;
        }

        private void numColor_Changed(object sender, System.EventArgs e)
        {
            color = Color.FromArgb((int)numA.Value, (int)numR.Value, (int)numG.Value, (int)numB.Value);
            updateColorUI();
        }

        private void colorDisplay_Click(object sender, System.EventArgs e)
        {
            colorPicker.ShowDialog();

            int r = colorPicker.Color.R;
            int g = colorPicker.Color.G;
            int b = colorPicker.Color.B;

            color = Color.FromArgb(255, r, g, b);
            updateColorUI();
        }

        private void colorDisplay_MouseEnter(object sender, System.EventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void colorDisplay_MouseLeave(object sender, System.EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

    }
}