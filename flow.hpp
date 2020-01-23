#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_FLOW
    #define FLOW_PUBLIC __declspec(dllexport)
  #else
    #define FLOW_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_FLOW
      #define FLOW_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define FLOW_PUBLIC
  #endif
#endif

namespace flow {

class FLOW_PUBLIC Flow {

public:
  Flow();
  int get_number() const;

private:

  int number;

};

}

