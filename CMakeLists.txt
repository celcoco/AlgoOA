cmake_minimum_required(VERSION 3.5)
project(AlgoOA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
        TestPlat.h
        TestPlat.cpp
        SlnBase.h
        main.cpp
        PrintAll.h
        Tree.h
        MajorityElement.cpp
        PrintAll.cpp
        MoveZeros.cpp
        isValid.cpp
        MatchingPair.cpp
        MiniGates.cpp
        PairChar.cpp
        AkunaT1.cpp
        AkunaT2.cpp
        PilNum.cpp
        UniWordCnt.cpp
        AkunaT5.cpp
        AkunaT6.cpp
        LowestTreeDist.cpp
        Tree.cpp
        )

add_executable(AlgoOA ${SOURCE_FILES})
