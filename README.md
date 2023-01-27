# moos-ivp-arcturus

This repository contains all MOOS-IvP code for Arcturus Navigations. 

## Installation

### Step 1: Download the MOOS-IvP software

Follow the instructions on the [2.680 Lab](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=Lab.ClassSetup) to download and build the MOOS-IvP software and its dependencies.

### Step 2: Clone this repository

Clone this repository into your home directory and run the following commands:

```
cd moos-ivp-arcturus
./build.sh
```

### Step 3: Set up PATH variables

Choose your favorite editor (e.g. `nano`) to add the following lines to `~/.bashrc` (or `~/.zshrc` if you are using zsh).

```
export PATH=~/moos-ivp/bin:$PATH
export PATH=~/moos-ivp/scripts:$PATH
export PATH=~/moos-ivp/moos-ivp-arcturus/bin:$PATH
```

This will add the paths to execute your scripts.

## How to use

### Creating a new MOOS project

To create a new MOOS-IvP app, run the `GenMOOSApp [app-name] [prefix]` or the `GenMOOSApp_AppCasting [app-name] [prefix]` command if you want an [AppCasting](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=IvPTools.AppCastingIntro) MOOS App. The prefix is typically 'p'.

For example, to create a `pOdometry` project, you run 

```
cd ~/moos-ivp-arcturus/src
GenMOOSApp_AppCasting Odometry p
```

To build this newly created MOOS application, you need to include the line 

```
ADD_SUBDIRECTORY([app-name])
```

Inside the `src/CMakeLists.txt` file. For example, to add the `pOdometry` app to your build directories, add the following line to `src/CMakeLists.txt`:

```
ADD_SUBDIRECTORY(pOdometry)
```

Check that the project was successfully built by ensuring that a new script with the name of your MOOS app has been added to `moos-ivp-arcturus/bin/`.

### Using a MOOS application 

To use your MOOS application, `cd` into the `missions` directory and create a new `.moos` and/or `.bhv` file for your project. More on `.moos` files [here](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=Lab.ClassIntroMOOS#section1.2) and more on `.bhv` files [here](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=Lab.ClassHelmAutonomy).

Once your `.moos` and `.bhv` files are ready, launch your mission by using [pAntler](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=IvPTools.PAntler):

```
pAntler [example.moos]
```

You may also want to make your mission run faster by using something like

```
pAntler --MOOSTimeWarp=10 [example.moos]
```
