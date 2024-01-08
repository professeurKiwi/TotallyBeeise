#ifndef CONFIGURATIONS
#define CONFIGURATIONS

#define ENABLE_SERIAL 0

#if ENABLE_SERIAL == 1
#define println(str) (Serial.println(str))
#define print(str) (Serial.print(str))
#else
#define println(str)  
#define print(str)  
#endif

#endif