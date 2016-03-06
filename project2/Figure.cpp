//
//  Figure.cpp
//  project2
//
//  Created by MR_gong on 16/3/3.
//  Copyright © 2016年 gong. All rights reserved.
//
#include "Tetris.hpp"
#include "Common.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
extern Game tetrisGame;

Figure::Figure(){
    int numFigure = rand() % NUM_FIGURE;
    New(numFigure);
}
Figure::Figure(int numFigure){
    New(numFigure);
}
Figure::~Figure(){
    
}
void Figure::New(int numFigure){
    if(numFigure >=0 && numFigure < NUM_FIGURE){
        canRotate = (numFigure != 0);
        posX = NUM_BLOCKS_X /2;
        posY = NUM_BLOCKS_Y - 2;
        if(tetrisGame.GetMap(posX, posY+1) == USED && tetrisGame.GetStatus()){
            tetrisGame.SetStatus(false);
            return;
        }
        
        for(int i = 0; i < NUM_FIGURE_BLOCK;++i){
            data[i].SetPosX(posX + image[numFigure][i][0]);
            data[i].SetPosY(posY + image[numFigure][i][1]);
            
        }
        
    }
}

void Figure::Draw() const{
    for (int i = 0; i < NUM_FIGURE_BLOCK; i++) {
        data[i].Draw();
    }
}
bool Figure::Rotate(){
    if(!canRotate)
        return false;
    for (int i = 0 ; i < NUM_FIGURE_BLOCK; i++) {
        if(!data[i].CanRotate(posX, posY))
            return false;
    }

    for (int i = 0; i < NUM_FIGURE_BLOCK; i++) {
        data[i].Rotate(posX, posY);
    }

    return true;
    
}

bool Figure::Translate(const int offsetX, const int offsetY){
    for (int i = 0; i < NUM_FIGURE_BLOCK; i++) {
        if (!data[i].CanTranslate(offsetX, offsetY)) {
            return false;
        }
    }
    for (int i = 0; i < NUM_FIGURE_BLOCK; i++) {
        data[i].Translate(offsetX, offsetY);
    }
    SetPosX(posX+offsetX);
    SetPosY(posY+offsetY);
    return true;
    
}





