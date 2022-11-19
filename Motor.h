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
    public:
        Motor(int step, int dir);
        void init();
        void note(int num);
        bool getInUse() const;
};

#endif
