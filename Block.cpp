//
//  Block.cpp
//  project2
//
//  Created by MR_gong on 16/3/1.
//  Copyright © 2016年 gong. All rights reserved.
//

#include "Common.h"
#include "Tetris.hpp"
#include <stdlib.h>
extern Game tetrisGame;
Block::Block(){
    posX = NUM_BLOCKS_X/2;
    posY = NUM_BLOCKS_Y - 1;
}
Block::~Block(){
    
}

void Block::Draw()const{
    int left = posX * (BLOCK_SIZE + BLOCK_SPACING) -BLOCK_SPACING;
    int right = left + BLOCK_SIZE;
    int bottom = posY * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
    int top = bottom + BLOCK_SIZE;
    
    //opengL
    
    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glVertex3f(left, top, 0);
    glVertex3f(right, top, 0);
    glVertex3f(right, bottom, 0);
    glVertex3f(left, bottom, 0);
    glEnd();
    
    
}
//void Block::Draw() const {
//    
//    // 获得方块坐标
//    int left = posX * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
//    int right = left + BLOCK_SIZE;
//    int bottom = posY * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
//    int top = bottom + BLOCK_SIZE;
//    
//    // 调用OpenGL库函数显示方块
//    glBegin(GL_QUADS);
//    glColor3d(1,1,1);
//    glVertex3f(left, top, 0);
//    glVertex3f(right, top, 0);
//    glVertex3f(right, bottom, 0);
//    glVertex3f(left, bottom, 0);
//    glEnd();
//}
bool Block::CanRotate(const int figureX, const int figureY) const{
    
    int offsetX = posX - figureX;
    int offsetY = posY - figureY;
    
    int newposX = figureX - offsetY;
    int newposY = figureY + offsetX;
    
    if(!offsetX && !offsetY){
        return true;
    }
    if(tetrisGame.GetMap(newposX, newposY)!=EMPTY)
        return false;
    
    int tempX[3],tempY[3];
    tempX[0] = newposX + offsetX;
    tempY[0] = newposY + offsetY;
    
    if( abs(offsetX) > 1 || abs(offsetY) > 1){
        tempX[1] = (posX + tempX[0])/2;
        tempY[1]= (posY + tempY[0])/2;
        tempX[2]= (newposX + tempX[0])/2;
        tempY[2]= (newposY + tempY[0])/2;
        
        if(tetrisGame.GetMap(tempX[1], tempY[1] !=EMPTY) || tetrisGame.GetMap(tempX[2], tempY[2])!=EMPTY)
            return false;
    }else if(abs(offsetX) == 1 && abs(offsetY) == 1){
        tempX[1] = (newposX + posX) /2;
        tempY[1] = (newposY + posY) /2;
        if (tetrisGame.GetMap(tempX[1], tempY[1])!=EMPTY) {
            return false;
        }
        
    }else if(tetrisGame.GetMap(tempX[0], tempY[0])!=EMPTY)
        return false;
    
    return true;
    
}
bool Block::Rotate(const int figureX, const int figureY){
    if(!CanRotate(figureX, figureY))
        return false;
    int offsetX = posX - figureX;
    int offsetY = posY - figureY;
    
    int newposX = figureX - offsetY;
    int newposY = figureY + offsetX;
    
    SetPosX(newposX);
    SetPosY(newposY);
    return true;
}
bool Block::CanTranslate(const int offsetX, const int offsetY) const{
    if(tetrisGame.GetMap(posX + offsetX, posY+ offsetY) != EMPTY)
        return false;
    return true;
    
}
bool Block::Translate(const int offsetX, const int offsetY){
    int newposX = posX + offsetX;
    int newposY = posY + offsetY;
    if(!CanTranslate(offsetX, offsetY))
        return false;
    SetPosX(newposX);
    SetPosY(newposY);
    return true;
}






