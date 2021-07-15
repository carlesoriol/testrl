
uint8_t dotsNumbers[6] =
{
    // bits order
    // 0   1
    // 2 3 4
    // 5   6

    0b00001000, //1
    0b00100010, //2
    0b00101010, //3
    0b01100011, //4
    0b01101011, //5
    0b01110111, //6
};

uint8_t dotsPos[4][2][7][2] =
// order
// 0   1
// 2 3 4
// 5   6
// dot x,y
// 0xff, 0xff, no point
{
    {
        {
            {3,3},          {11,3},
            {3,7},  {7,7},  {11,7},
            {3,11},         {11,11},
        },
        {
            {3,4},          {11,4},
            {3,8},  {7,8},  {11,8},
            {3,12},         {11,12},
        },
    },

    {
        {
            {4,2},          {10,2},
            {3,5},  {7,5},  {11,5},
            {3,8},          {11,8},
        },
        {
            {3,12},          {11,12},
            {3,13},  {7,13}, {11,13},
            {4,14},          {10,14},
        },
    },

    {
        {
            {4,2},          {10,2},
            {3,4},  {7,4},  {11,4},
            {3,6},          {11,6},
        },
        {
            {3,10},          {11,10},
            {3,12},  {7,12}, {11,12},
            {4,14},          {10,14},
        },
    },

    {
        {
            {4,2},          {10,2},
            {3,3},  {7,3},  {11,3},
            {3,4},          {11,4},
        },
        {
            {3,8},           {11,8},
            {3,11},  {7,11}, {11,11},
            {4,14},          {10,14},
        },
    },
};

uint8_t diceImage[21*3];

uint8_t dicePreImages[4][21*3] = 
{
    {
        0b01111111, 0b11111110, 0b00000000, 
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000, 
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,

        0b01000000, 0b00000010, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,

        0b00111111, 0b11111100, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000, 
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b01111111, 0b11111110, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        
        0b00111111, 0b11111100, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,
        0b10000000, 0b00000001, 0b00000000,

        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,
        0b01000000, 0b00000010, 0b00000000,

        0b00111111, 0b11111100, 0b00000000, 
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    }
};


uint8_t diceMask[4][21*3] = 
{
    {
        0b01111111, 0b11111110, 0b00000000, 
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000, 
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b01111111, 0b11111110, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b00111111, 0b11111100, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000, 
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b01111111, 0b11111110, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        
        0b00111111, 0b11111100, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    },
    {
        0b00111111, 0b11111100, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,
        0b11111111, 0b11111111, 0b00000000,

        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,
        0b01111111, 0b11111110, 0b00000000,

        0b00111111, 0b11111100, 0b00000000, 
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,
        0b00000000, 0b00000000, 0b00000000,

        0b00000000, 0b00000000, 0b00000000,
    }
};



