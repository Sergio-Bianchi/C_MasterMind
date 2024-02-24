cmake_minimum_required(VERSION 3.27)
project(C_MasterMind C)

set(CMAKE_C_STANDARD 11)

add_executable(C_MasterMind main.c
        define.h
        colors.h
        graphic.c
        utils.c
        leaderboard.c
        game.c
        functions.h
        functions.h
)
