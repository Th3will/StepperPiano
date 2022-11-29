#ifndef PLAYER
    #define PLAYER
    #include <arduino.h>
       class Motor{
    private:
        //Device info
        // using a 200-step motor (most common)
        const int motorSteps = 200;

        //driver
        int stepPin; 
        int dirPin;
        bool inUse = false;
        bool dir;
        int del;
        bool isPressed;
        int oct = 5;
        int count;
    public:
        Motor(int step, int dir);
        void init();
        void play(int delay);
        bool getInUse() const;
};

#endif
