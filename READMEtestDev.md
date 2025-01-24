# About

This is for testing circuits and simulations of circuits.
Code in this branch is similar only in IO. 


Uses: 
www.tinkedcad.com



# Testing data
## Tinkedcad
Moistsensor in analog read:
    0-876


## Arduino R3


# PsudoCode

Använd 
    unsigned long previousMillis = 0;
med denna if sats i loop
if (currentMillis - previousMillis >= interval){
    
    previousMillis = currentMillis;
    [[Pump effect]]
}

