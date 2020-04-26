namespace routes
{
    void rec();
    void startRec();
    void stopRec();
    void replay();
    void startReplay(float startTime);
    void stopReplay();
    void reset();
    void saveFile(const std::string &desc);
    void loadFile(unsigned int num);
    void find(const std::string &needle);
    void listAll();
    LuaRef getTable();
    unsigned int loadAll();
    unsigned int loadTeam();
    unsigned int loadEnemy();
    void enableBot(bool on);

    void flagGrab(float grabtime);
    void tickRecord(ATrPlayerController * pc);
    void tickReplay(float deltaTime, bool firstRun = false, size_t startPos = 0);
    void UpdateOverheadNumbers(ATrHUD *that);

    extern bool botReplay;
}