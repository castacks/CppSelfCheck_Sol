
# C++ Skills Self-Check 

# One solution

Make sure you have Egien and OpenCV installed. Assuming the Linux system is Ubuntu.

```bash
sudo apt-get update
sudo apt-get install build-essential cmake git libeigen3-dev libopencv-dev
```

Then clone and build the project for running.

```bash
cd <CppSelfCheck_Sol>
mkdir build_release
cd build_release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

To run the target.

```bash
cd build_release
./CppSelfCheck_exe ../data/opencv_logo.png
```

For debugging, do

```bash
cd <CppSelfCheck_Sol>
mkdir build_debug
cd build_debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

The following is an example of the `launch.json` required by Visual Studio Code to do the debugging.

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "CppSelfCheck Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build_debug/CppSelfCheck_exe",
            "args": ["../data/opencv_logo.png"],
            "cwd": "${workspaceFolder}/build_debug"
        }
    ]
}
```
