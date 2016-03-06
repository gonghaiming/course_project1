//
//  Tetris.hpp
//  project2
//
//  Created by MR_gong on 16/3/1.
//  Copyright © 2016年 gong. All rights reserved.
//

#ifndef Tetris_hpp
#define Tetris_hpp

#include "Common.h"
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGl/gl.h>

class Block{
private:
    int posX,posY;
public:
    Block();
    virtual ~Block();
    
    void Draw() const;
    
    bool CanRotate(const int figureX,const int figureY) const;
    
    bool Rotate(const int figureX,const int figureY);
    
    bool Translate(const int offsetX,const int offsetY);
    
    bool CanTranslate(const int offsetX,const int offsetY) const;
    
    Block & operator = (Block & other){
        if(this != &other){
            SetPosX(other.GetPosX());
            SetPosY(other.GetPosY());
        }
        return *this;
    }
    
    int GetPosX()const{return posX;};
    int GetPosY()const{return posY;};
    
    void SetPosX(const int x){posX = x;}
    void SetPosY(const int y){posY = y;}
    
    
};
class Figure {
public:
    Block data[NUM_FIGURE_BLOCK];
    Figure(int numFigure);
    Figure();
    virtual ~Figure();
    
    void New(int numFigure);
    
    void Draw() const;
    
    bool Rotate();
    
    bool Translate(const int offsetX,const int offsetY);
    
    int GetPosX() const {return posX;}
    int GetPosY() const {return posY;}
    
    void SetPosX(const int x) { posX = x;}
    void SetPosY(const int y) { posY = y;}
private:
    int posX,posY;
    bool canRotate;
};

class Game{
public:
    Game();
    virtual ~Game();
    
    void Draw() const;
    
    void Update(const Figure &figure);
    
    bool RowIsFull(const int row) const;
    
    void ClearRow(const int row);
    
    void New();
    
    int GetMap(const int x,const int y) const;
    
    bool GetStatus() const {return status;}
    void SetStatus(bool newStatus){
        status = newStatus;
    }
    
    void DrawGameOutline() const;
    
    void DrawGameExtraInfo() const;

        int currentScore;
private:
    int num_row,num_col;
    int map[MAX_BLOCK_NUM][MAX_BLOCK_NUM];

    bool status;
    


};




#endif /* Tetris_hpp */
