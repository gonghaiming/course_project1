//
//  Common.h
//  project2
//
//  Created by MR_gong on 16/3/1.
//  Copyright © 2016年 gong. All rights reserved.
//

#ifndef Common_h
#define Common_h

#define NUM_FIGURE 7

#define NUM_FIGURE_BLOCK 4

#define BLOCK_SIZE 19

#define BLOCK_SPACING 1

#define MAX_BLOCK_NUM 100

#define WINDOW_WIDTH 350

#define WINDOW_HEIGHT 500

#define NUM_BLOCKS_X WINDOW_WIDTH/(BLOCK_SIZE + BLOCK_SPACING)

#define NUM_BLOCKS_Y WINDOW_HEIGHT/(BLOCK_SIZE +BLOCK_SPACING)

#define USED 1

#define EMPTY 0

#define RUNNING 1

#define LOSE 0

const int image[NUM_FIGURE][NUM_FIGURE_BLOCK][2]={
    {
        {0,0},
        {0,1},
        {1,1},
        {1,0}
    },
    {
        {0,-1},
        {0,0},
        {0,1},
        {0,2}
    },
    {
        {0,1},
        {-1,1},
        {-1,0},
        {-1,-1}
    },
    {
        {0,1},
        {-1,1},
        {-1,0},
        {-1,-1}
    },
    {
        {-1,1},
        {-1,0},
        {0,0},
        {0,-1}
    },
    {
        {0,1},
        {0,0},
        {-1,0},
        {-1,-1}
    },
    {
        {-1,0},
        {0,0},
        {1,0},
        {0,1}
    }
};



#endif /* Common_h */
