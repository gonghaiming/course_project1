//
//  Game.cpp
//  project2
//
//  Created by MR_gong on 16/3/1.
//  Copyright © 2016年 gong. All rights reserved.
//

#include "Common.h"
#include "Tetris.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern Figure tetrisFigure;
Game::Game(){
    num_col = (WINDOW_WIDTH)/(BLOCK_SIZE + BLOCK_SPACING);
    num_row = (WINDOW_HEIGHT)/(BLOCK_SIZE + BLOCK_SPACING);
    currentScore = 0;
    status = true;
    
}

Game::~Game(){
    
}
void Game::DrawGameOutline() const{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.2,0.1);
    glVertex3f(0, 0, 0);
    glVertex3f(WINDOW_WIDTH - BLOCK_SIZE/2, 0, 0);
    glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2, WINDOW_HEIGHT, 0);
    glVertex3f(0, WINDOW_HEIGHT, 0);
    glEnd();
    
}
void Game::DrawGameExtraInfo() const{
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.2, 0.1);
    glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2, 0, 0);
    glVertex3f(WINDOW_WIDTH - BLOCK_SIZE/2 +100 , 0, 0);
    glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2 + 100, WINDOW_HEIGHT, 0);
    glVertex3f(WINDOW_WIDTH -BLOCK_SIZE/2, WINDOW_HEIGHT, 0);
    glEnd();
}


void Game::Draw() const{
    DrawGameOutline();
    DrawGameExtraInfo();
    
    char scoreLabelText[] = "score";
    glRasterPos2f(WINDOW_WIDTH-BLOCK_SIZE/2 +10, WINDOW_HEIGHT-20);
    int len = (int)strlen(scoreLabelText);
    for(int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreLabelText[i]);
    }
    
    char scoreText[10];
    sprintf(scoreText, "%d",currentScore);
    len = (int)strlen(scoreText);
        glRasterPos2f(WINDOW_WIDTH-BLOCK_SIZE/2 +10, WINDOW_HEIGHT-40);
    for(int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
    }
    
    
    if(status){
        Block block = Block();
        for (int i =0; i < num_row; ++i) {
            for (int j = 0;  j < num_col; j++) {
                if(map[i][j]){
                    block.SetPosX(j);
                    block.SetPosY(i);
                    block.Draw();
                }
                
                

            }
        }
    }else{
        char string[] = "GAME OVER";
        int len;
        glRasterPos2f(WINDOW_HEIGHT/2, WINDOW_WIDTH/2);
        len = (int) strlen(string);
        for(int i = 0; i < len;i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        }
    }
    
    
}
void Game::New(){
    int i,j;
    for(i = 0;i < num_row;i++){
        for(j = 0; j < num_col;++j){
            map[i][j] = EMPTY;
        }
    }
    tetrisFigure.New(rand()/NUM_FIGURE);
    status = true;
}
void Game::Update(const Figure &figure){
    int i,num;
    for(i = 0;i <NUM_FIGURE_BLOCK;i++){
        map[figure.data[i].GetPosY()][figure.data[i].GetPosX()] = USED;
    }
    num = figure.GetPosY();
    for(i = num + 2; i >= num-2; i--){
        if(RowIsFull(i)){
            ClearRow(i);
            currentScore = currentScore + 1;
        }
    }
    
}
void Game::ClearRow(const int row){
    int i,j;
    if(row<0 || row >=num_row)
        return;
    for(i = row;i<num_row-2;++i)
        for(j =0; j< num_col;++j)
            map[i][j] = map[i+1][j];
    for(j = 0; j < num_col;++j)
        map[num_row-1][j] = 0;
    
}
bool Game::RowIsFull(const int row) const{
    int i ;
    if(row < 0 || row >=num_row)
        return false;
    for(i = 0; i < num_col; ++i){
        if(map[row][i] == EMPTY)
            return false;
    }
    return true;
    
}
int Game::GetMap(const int x, const int y)const{
    if( (x < 0) || (y < 0) || x >=num_col || y >=num_row ){
        return -1;
    }else{
        return map[y][x];
    }
}

