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
        const int notes[8] = {(2024*oct)/10,(1912*oct)/10, (1703*oct)/10, (1517*oct)/10, (1431*oct)/10, (1275*oct)/10, (1136*oct)/10, (1012*oct)/10};
    public:
        Motor(int step, int dir);
        void init();
        void play(int note);
        bool getInUse() const;
};

#endif
