cmake_minimum_required(VERSION 3.26.4)
project(C_MasterMind C)

set(CMAKE_C_STANDARD 11)

add_executable(C_MasterMind main.c
        define.h
        colors.h
        utils.c
        leaderboard.c
        game.c
        functions.h
        printFiles.c
)
