# FCC
Welcome to the FCC project!

Fiuggi Compiler Collection (FCC) is a high-performance compiler based on LLVM.  
Our first release, FCC v0.6.alpha1, provides profiling aided automatic parallelization with more optimization features comming soon.

This test suite contains the FCC binaries for x86 / arm and all other libraries required to compile a benchmark.
The purpose of this test suite is mainly for people who are interested in the FCC compilation process to reproduce the results we have presented earlier. For people who would like to include FCC into their development toolchain, please kindly refer to the Cooperation section at the end of this readme file.
___
<!-- vscode-markdown-toc -->
* [Installation](#Installation)
	* [Install Dependencies](#InstallDependencies)
	* [Build](#Build)
* [Getting Started](#GettingStarted)
	* [Compilation process](#Compilationprocess)
	* [Run the binary](#Runthebinary)
* [Cooperation](#Cooperation)

<!-- vscode-markdown-toc-config
	numbering=false
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

| System | v0.6.alpha1 |
| :---: | :---: |
| Ubuntu 20.04.4 LTS x86 | [![Build Status](https://ci.pytorch.org/jenkins/job/pytorch-master/badge/icon)](https://ci.pytorch.org/jenkins/job/pytorch-master/) |
| Ubuntu 18.04.5 LTS aarch64 | [![Build Status](https://ci.pytorch.org/jenkins/job/pytorch-master/badge/icon)](https://ci.pytorch.org/jenkins/job/pytorch-master/) |
| Windows | [![Build Status](https://ci.pytorch.org/jenkins/job/pytorch-builds/job/pytorch-win-ws2016-cuda9-cudnn7-py3-trigger/badge/icon)](https://ci.pytorch.org/jenkins/job/pytorch-builds/job/pytorch-win-ws2016-cuda9-cudnn7-py3-trigger/) |
| MacOS | [![Build Status](https://ci.pytorch.org/jenkins/job/pytorch-builds/job/pytorch-win-ws2016-cuda9-cudnn7-py3-trigger/badge/icon)](https://ci.pytorch.org/jenkins/job/pytorch-builds/job/pytorch-win-ws2016-cuda9-cudnn7-py3-trigger/) |



## <a name='Installation'></a>Installation

### <a name='InstallDependencies'></a>Install Dependencies
```bash
gcc==8.4.0
g++==8.4.0
expect==latest
```

```bash
sudo apt-get install expect

sudo apt-get install gcc-8
sudo apt-get install g++-8

sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 100
sudo update-alternatives --config gcc

sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-8 100
sudo update-alternatives --config g++

```


### <a name='Build'></a>Build
```bash
git clone -b x86 https://github.com/THeWakeSystems/fcc.git
# If you use arm machine
# git clone -b arm https://github.com/THeWakeSystems/fcc.git
make
source shrc
```

## <a name='GettingStarted'></a>Getting Started

### <a name='buildbenchmarks'></a>Build Benchmarks
1. Cd to the source file directory of each benchmark.
```bash
#For Example
cd ./tests/benchmarks/2mm/src
```
2. Source the corresponding execInfo. Each benchmark needs a "sourceable" file to determine the inputs for profiling and the actual run.
```bash
#For Example
source ../execInfo
```

3. One step compilation
```bash
fcc <source_file> -p <output_file>
#For Example
fcc 2mm.c -p 2mm
```

4. Run the binary

```bash
time NUM_WORKERS=<thread_number> <output_file> ${TESTARG}
#For Example
time NUM_WORKERS=4 ./2mm ${TESTARG}
```
The user needs to specify the number of threads to run.

### <a name='buildsamples'></a>Build Samples

1. Cd to the source file directory of each sample.

```bash
#For Example
cd ./tests/samples/1
```

2. One step compilation
```bash
fcc code.cpp -p <output_file>
#For Example
fcc code.cpp -p test
```
3. Run the binary

```bash
time NUM_WORKERS=<thread_number> <output_file> < <input_file>
#For Example
time NUM_WORKERS=4 ./test < input.txt
```

The user needs to specify the number of threads to run.

## <a name='Cooperation'></a>Cooperation

Please be noted that our current FCC 0.6.alpha1 is still in the early stage. For anyone who is interested in FCC and would like to reproduce the results, please feel free to follow the instructions presented in the README file.

However, if your team would like to include FCC into your own development toolchain, may we courteously ask you to contact our product team at zuoquan.he@thewakesystems.com.  We will get back to you with more detailed information as soon as we receive your requst. We are happy to work with your team to fulfil your requests and, in the meanwhile, make our future versions successful releases.
