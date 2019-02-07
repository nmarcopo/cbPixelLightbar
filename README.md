# Typing Lightbar for 2015 Chromebook Pixel

![](https://thumbs.gfycat.com/MediocreSpeedyAnura-size_restricted.gif)  

This is a simple C program that will change your Pixel's lightbar to a random color each time you press a key. The color persists for less than a second before it returns to the default colors.  

## Setting up

- Make sure your device is in dev mode. Take a look at [this article](https://www.androidcentral.com/how-enable-developer-mode-chrome-os) if you need help setting that up.
- Enter the shell and navigate to the `cbPixelLightbar.c` file from this repository.
- You might need to re-mount your Pixel's drive without the `noexec` flag. Follow the instructions located at [this Stack Exchange page](https://superuser.com/questions/1264615/permission-denied-on-chromebook-even-with-sudo).
- Compile the program with gcc using this command: `gcc cbPixelLightbar.c -o cbPixelLightbar`
- Run the program with `./cbPixelLightbar`, or `./cbPixelLightbar &` if you want to have the process persist in the background.
