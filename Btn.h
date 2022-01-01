#pragma once

struct BtnFlags {
    bool _btnState : 1;
    bool _btnFlag : 1;
    bool _btnHoldF : 1;
    bool _stepHoldF : 1;

    bool _btnPressFlag : 1;
    bool _btnReleaseFlag : 1;
    bool _btnHoldFlag : 1;
};

class Btn {
public:
    BtnFlags BtnFlags;
    Btn(uint8_t pin, uint8_t deb = 50, uint8_t stepT = 200) {
        _pin = pin;
        _deb = deb;
        _stepT = stepT;
        pinMode(_pin, INPUT_PULLUP);
    }

    void tick() {
        BtnFlags._btnState = !digitalRead(_pin);
        /*
          if (btnState && !BtnFlags && (millis() - tmr > 20)) {
            BtnFlags = true;
            tmr = millis();
            debug("press");
          }
        */
        if (BtnFlags._btnState && !BtnFlags._btnFlag && (millis() - _tmr > _deb)) {
            BtnFlags._btnFlag = true;
            BtnFlags._btnPressFlag = true;
            _tmr = millis();
            _hold = millis();
            //debug("press");
        }

        if (!BtnFlags._btnState && BtnFlags._btnFlag) {
            BtnFlags._btnFlag = false;
            BtnFlags._btnHoldF = false;
            BtnFlags._stepHoldF = false;
            BtnFlags._btnReleaseFlag = false;
            BtnFlags._btnHoldFlag = false;
            //debug("release");
        }

        if (BtnFlags._btnState && BtnFlags._btnFlag && !BtnFlags._btnHoldF && (millis() - _hold > 1000)) {
            BtnFlags._btnHoldF = true;
            BtnFlags._btnHoldFlag = true;
            _hold = millis();
            //debug("hold");
        }

        if (BtnFlags._btnHoldF && (millis() - _stepHold > _stepT)) {
            _stepHold = millis();
            BtnFlags._stepHoldF = true;
            //debug("step hold");
        }
    }

    bool isHold() {
        if (BtnFlags._btnHoldFlag) {
            BtnFlags._btnHoldFlag = false;
            return true;
        } else return false;
    }

    bool isHolded() { //step
        if (BtnFlags._stepHoldF) {
            BtnFlags._stepHoldF = false;
            return true;
        } else return false;
    }

    bool isPress() {
        if (BtnFlags._btnPressFlag) {
            BtnFlags._btnPressFlag = false;
            return true;
        } else return false;
    }

    bool isRelease() {
        if (!BtnFlags._btnReleaseFlag) {
            BtnFlags._btnReleaseFlag = true;
            return true;
        } else return false;
    }

private:
    uint8_t _pin;
    uint16_t _deb;
    uint16_t _stepT;

    uint16_t _tmr;
    uint16_t _hold;
    uint16_t _stepHold;
};
