using System;
using System.Drawing;
using System.Drawing.Imaging;

namespace RandomImageProcessor
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the path of the image file: ");
            string filePath = Console.ReadLine();

            // Load the image
            using (Bitmap bitmap = new Bitmap(filePath))
            {
                Random rand = new Random();

                for (int y = 0; y < bitmap.Height; y++)
                {
                    for (int x = 0; x < bitmap.Width; x++)
                    {
                        Color originalColor = bitmap.GetPixel(x, y);

                        // Generate a random multiplier between 0.3 and 1.0
                        double multiplier = .5 + (rand.NextDouble() * 0.7);

                        // Apply the multiplier to each color channel
                        int red = (int)(originalColor.R * multiplier);
                        int green = (int)(originalColor.G * multiplier);
                        int blue = (int)(originalColor.B * multiplier);

                        red = Math.Clamp(red, 0, 255);
                        green = Math.Clamp(green, 0, 255);
                        blue = Math.Clamp(blue, 0, 255);

                        Color newColor = Color.FromArgb(originalColor.A, red, green, blue);
                        bitmap.SetPixel(x, y, newColor);
                    }
                }

                string newFilePath = "modified_" + System.IO.Path.GetFileName(filePath);
                bitmap.Save(newFilePath, ImageFormat.Png);

                Console.WriteLine($"Modified image saved as {newFilePath}");
            }
        }
    }
}
