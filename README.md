# moos-ivp-arcturus

This repository contains all MOOS-IvP code for Arcturus Navigations, including iMOOSGateway to connect MOOS to ROS.

## Installation

### Step 1: Download the MOOS-IvP software

Follow the instructions on the [2.680 Lab](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=Lab.ClassSetup) to download and build the MOOS-IvP software and its dependencies. Clone the base MOOS-IvP software into your home directory, else you would need to edit the `MOOSIVP_SOURCE_TREE_BASE` paths in CMakeLists.txt.

### Step 2: Clone this repository

Clone this repository into your desired directory and run the following commands to ensure that your setup is complete.

```
cd moos-ivp-arcturus
./clean.sh
./build.sh
```

### Step 3: Set up PATH variables

Choose your favorite editor (e.g. `nano`) to add the following lines to `~/.bashrc` (or `~/.zshrc` if you are using zsh).

```
export PATH=~/moos-ivp/bin:$PATH
export PATH=~/moos-ivp/scripts:$PATH
export PATH=[YOUR_MOOS-IvP_DIRECTORY]/bin:$PATH
```

Please substitute `YOUR_MOOS-IvP_DIRECTORY` with the directory where you cloned this repository. This will add the paths to execute your scripts.

## How to use

### Creating a new MOOS project

To create a new MOOS-IvP app, run the `GenMOOSApp [app-name] [prefix]` or the `GenMOOSApp_AppCasting [app-name] [prefix]` command if you want an [AppCasting](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=IvPTools.AppCastingIntro) MOOS App.

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

### Connecting MOOS-IvP to ROS

This repository also contains the `iMOOSGateway` app which connects MOOS-IvP and ROS through publishing/subscribing variables to MOOSDB. More on the iMOOSGateway [here](https://github.mit.edu/AUVLab/moos-ivp-gateway) and the ROS node that bridges the two software [here](https://github.mit.edu/AUVLab/protobuf_client).

`moos-gateway-alpha` is an example mission that uses `iMOOSGateway`. After running `./launch.sh`, open another terminal window and run `roscore`. Then, open another terminal window again, `cd` into your ROS workspace with `protobuf_client` built (e.g. `AllSeaingVehicle`), and source the `devel/setup.bash` or `devel/setup.zsh` file. Finally, run the command `rosrun protobuf_client protobuf_client` to run the ROS node. This should establish a connection between the MOOS-IvP and ROS.

