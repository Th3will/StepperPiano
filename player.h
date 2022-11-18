#ifndef UTIL
    #define UTIL
    #include <arduino.h>
        class Player{
            private:
                //key values
                const int c=1912;
                const int cf=1805;
                const int d= 1703;
                const int df=1607;
                const int e=1517;
                const int f=1431;
                const int ff=1351;
                const int g= 1275;
                const int gf=1203;
                const int a=1136;
                const int af=1072;
                const int b=1012;
                const int c1=floor(c/2);
                const int cf1=floor(cf/2);
                const int d1=floor(d/2);
                const int df1=floor(df/2);
                const int e1=floor(e/2);
                const int f1=floor(1431/2);
                const int ff1=floor(1351/2);
                const int g1= floor(1275/2);
                const int gf1=floor(1203/2);
                const int a1=floor(1136/2);
                const int af1=floor(1072/2);
                const int b1=floor(1012/2);
                const int e0=e*2;
                const int g0=g*2;
                const int b0=b*2;
                const int af0=af*2;
                const int a0=a*2;
                const int f0=f*2;

                //Device info
                // using a 200-step motor (most common)
                const int motorSteps = 200;

                const int stepPin = 9; 
                const int dirPin = 8; 
                const int load = 7;
                const int clockIn = 6;
                const int dataIn = 5;
                const int clockEnablePin = 4;
                const int MS1 = 10;
                const int MS2 = 11;
                const int MS3 = 12;
                const int SLPRST = 13;

            public: 
                int getNote(int note){
                    return note;
                }
                void devInit();
        
};


#endif
