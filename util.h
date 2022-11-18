#ifndef UTIL
    #define UTIL
    class inpProc{
    private:
        byte incoming;
        bool switches[8] = {false,false,false,false,false,false,false,false};
        int place;
        int load; 
        int clockIn;
        int clockEnablePin;
        int dataIn;
    public: 
        inpProc();
        void GetData();
        void ByteFlips();
        bool CheckOnePress();
        void FlipAndPrintArray();
    };

#endif
