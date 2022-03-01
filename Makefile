BASE_DIR:=$(shell pwd)
BUILD_DIR:=$(BASE_DIR)/llvm-project/build
INSTALL_DIR:=${BASE_DIR}/llvm-install
JOBS?=32

CONFIG_LLVM = -G "Unix Makefiles" 																\
					-DCMAKE_BUILD_TYPE="Debug" 													\
					-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;compiler-rt;openmp;polly" 	\
					-DLLVM_TARGETS_TO_BUILD="ARM;AArch64" 										\
					-DLLVM_ENABLE_ASSERTIONS=ON 												\
					-DLLVM_ABI_BREAKING_CHECKS=FORCE_OFF 										\
					-DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} 										\
					-DCMAKE_CXX_STANDARD="17"


all: llvm-objects
.PHONY: llvm-objects clean

clean:
	rm -rf ${BUILD_DIR}
	rm -rf ${INSTALL_DIR}

llvm-objects: 
	git clone -b release/9.x https://github.com/llvm/llvm-project.git
	cd llvm-project; git apply ${BASE_DIR}/fcc-install/patch/llvm.patch
	mkdir -p ${INSTALL_DIR}
	mkdir -p ${BUILD_DIR}
	cd ${BUILD_DIR}; cmake ${CONFIG_LLVM} ${BASE_DIR}/llvm-project/llvm/; make -j${JOBS}; make install
