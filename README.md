# I2C Example

* The following guide describes how to use an existing library to communicate with a sensor via I2C.
* The I2C sensor is the color sensor ADJD-S311 from Avago. [LINK](https://www.sparkfun.com/products/retired/10701)

## Step 1: Download mbed CLI

* [Mbed CLI](https://docs.mbed.com/docs/mbed-os-handbook/en/latest/dev_tools/cli/#installing-mbed-cli) - Download and install mbed CLI.

## Step 2: Import I2C-Example project

Import I2C-Example project from GitHub.

```
mbed import https://github.com/mbed-Infineon-XMC/I2C-Example.git
```

## Step 3: Install ARM GCC toolchain

* [GNU ARM toolchain](https://launchpad.net/gcc-arm-embedded) - Download and install the last stable version of the ARM GCC toolchain.
* Open the file "mbed_settings.py" and add the ARM GCC install path.

Example:
```
#GCC_ARM_PATH = "home/bin/arm_gcc_toolchain/gcc-arm-none-eabi-5_4-2016q2/arm-none-eabi/bin"
```
## Step 4: Import ADJD-S311 library

* Jiaqi Xue provides an library to communicate with the color sensor. [LINK](https://os.mbed.com/users/Jiaqi/notebook/adjd-s311-i2c-color-sensor/)
```
cd I2C-Example.git/
mbed add http://mbed.org/users/CheeseW/code/ADJDs311/#5d0bc4df0701
```
> Make sure that mercurial version control is installed on your machine!

## Step 5: Compile project

Navigate into the project folder and execute the following command:
```
mbed compile -m XMC_4500_RELAX_KIT -t GCC_ARM
```
mbed creates a BUID directory where you can find the executables (bin, elf, hex ...).

## Step 6: Connect sensor with the XMC board.

![alt text](https://github.com/mbed-Infineon-XMC/I2C-Example/blob/master/ADJD-S311_con.png "Logo Title Text 1")

## Step 7: Flash to board

* [Segger JLink](https://www.segger.com/downloads/jlink) - Install the JLink software for your platform.
* Navigate to the BUILD directory and execute the following JLinkExe commands.
```
$ JLinkExe
J-LINK> device xmc4500-1024
J-LINK> h
J-Link> loadfile I2C-Example.git.hex
J-Link> r
J-Link> g
```
* Choose SWD, 4000kHz as interface settings!!
