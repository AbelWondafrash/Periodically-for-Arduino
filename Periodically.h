class Periodically {
  public:
    int patience = 1000;
    
    long lastTime;
    long originalTime;
    
    bool state;
    bool originalState;

    Periodically () {
      lastTime = millis ();
      originalTime = lastTime;
    }
    Periodically (int patience) {
      this -> patience = patience;
      new Periodically ();
    }
    Periodically (int patience, bool state) {
      this -> state = state;
      originalState = state;
      new Periodically (patience);
    }

    void setPatience (int patience) {
      this -> patience = patience;
    }
    void reset () {
      lastTime = millis ();
      state = originalState;
    }

    int elapsedTime () {
      return millis () - lastTime;
    }
    int elapsedOriginalTime () {
      return millis () - originalTime;
    }

    bool getState () {
      itsTime ();
      return state;
    }

    boolean itsTime () {
      if (pastTime ()) {
        lastTime = millis ();
        state = !state;
        return true;
      }
      return false;
    }
    boolean pastTime () {
      return elapsedTime () > patience;
    }
    boolean pastOriginalTime () {
      return elapsedOriginalTime () > patience;
    }
    boolean pastHalfTime () {
      return elapsedTime () > patience/2.0;
    }
};
