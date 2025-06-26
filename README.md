# FBXWriter

This is originally from Belle II Geometry exporters.

#################################################
# Belle II Geometry exporters

Here you can find the geometry exporters written to export the Belle II geometry.

Shared by Leo Piilonen (Virginia Tech).

More info can be found here:

 * http://www1.phys.vt.edu/~piilonen/VR/
 * https://docs.belle2.org/record/1036/files/BELLE2-POSTER-CONF-2018-007.pdf
#################################################

**Operation Manual**

** Please use your own path instead of <...>, and "/path/to/..." ***

1. Before you start to convert files, make sure you have set up a c++ 11, and can run the code under Geant4 4.10+.
  source <Path_to_ExternalLib>/gcc/<version>/x86_64-centos7/setup.sh
  source <Geant4_Install_Dir>/bin/geant4.sh
2. Define XML parser library paths:  
  export XERCESCROOT=<XercesC_Install_Path>  
  export LD_LIBRARY_PATH=${XERCESCROOT}/lib:$LD_LIBRARY_PATH
3. Configure math library dependencies:
  export CLHEP_BASE_DIR=<CLHEP_Install_Path>  
  export LD_LIBRARY_PATH=${CLHEP_BASE_DIR}/lib:$LD_LIBRARY_PATH
4. Include paths for project-specific libraries:
  export LD_LIBRARY_PATH=<Custom_Library_Path>:$LD_LIBRARY_PATH  
5. modify mainFBX.cc:
  write down the correct file names
6. make (if you change the .cc file's name, remember to modify it here.):
  export FBX_DIR=/path/to/custom/fbx/library          # Path to FBX library directory  
  export G4INSTALL=/path/to/geant4/install           # Geant4 installation directory  
  export G4INCLUDE=${G4INSTALL}/include/Geant4       # Geant4 header files  
  export CLHEP_BASE_DIR=/path/to/clhep/installation  # CLHEP library directory
  gcc -c FBXWriter.cc -Wall -std=c++11 -fPIC \  
    -I ./ -I $G4INCLUDE -I ${CLHEP_BASE_DIR}/include/ \  
    -L ${G4INSTALL}/lib64/ \  
    -lG4global -lG4clhep -lG4ptl -lG4materials -lG4intercoms -lG4zlib \  
    -lG4geometry -lG4graphics_reps -lG4modeling -lG4persistency \  
    -L ${CLHEP_BASE_DIR}/lib/ -lCLHEP-Vector-2.4.4. \  
    -I ${XERCESCROOT}/include/ -L ${XERCESCROOT}/lib/ -lxerces-c \  
    -lstdc++ -lm  
  gcc -shared FBXWriter.o -o libFBXWriter.so
  gcc -o mainFBX.exe mainFBX.cc -Wall -std=c++11 -fPIC \  
    -I ./ -I $G4INCLUDE -I ${CLHEP_BASE_DIR}/include/ \  
    -L ${G4INSTALL}/lib64/ \  
    -lG4global -lG4clhep -lG4ptl -lG4materials -lG4intercoms \  
    -lG4zlib -lG4geometry -lG4graphics_reps -lG4modeling -lG4persistency \  
    -L ${CLHEP_BASE_DIR}/lib/ -lCLHEP-Vector-2.4.4.0 \  
    -L ${FBX_DIR} -lFBXWriter \  
    -I ${XERCESCROOT}/include/ -L ${XERCESCROOT}/lib/ -lxerces-c \  
    -lstdc++ -lm  
7. ./mainFBX.exe


