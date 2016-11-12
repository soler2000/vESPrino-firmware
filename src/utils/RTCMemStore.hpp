#ifndef RTCMemStore_h
#define RTCMemStore_h
#include <RunningAverageSt.h>

#define GEN_MSCOUNTER 0
#define GEN_LASTTIME 1
struct RTCData {
  uint32_t crc32;
  uint32_t interations = 0;
  uint32_t millisStartIteration;
  uint32_t inDeepSleep = 0;
  uint32_t genData[5];
  RunningAverageSt avg1;
  uint8_t padding[3];
  char lastDweetCreated[30];
  static int rtcDataSize() {
    return (sizeof(struct RTCData)/4) * 4;
  }
};
// struct RTCData2 {
//   uint32_t crc32;
//   uint8_t data[508];
// };

class RTCMemStore {
public:
  void init();
  uint8_t getIterations();
  void setIterations(uint8_t i);
  double getAverage();
  void addAverageValue(double val, int weight = 1);
  static uint32_t getMillis();
  void addMillis(uint32_t ms);
  static uint32_t getGenData(int idx);
  static void setGenData(int idx, uint32_t value);
  bool wasInDeepSleep();
  void setDeepSleep(bool state);
  void clear();

  void setLastDweet(const char *s);
  void getLastDweet(char *buf);

  static RTCData *rtcData;
  static bool dataExisted;
  static bool getDataExisted();
  static bool test;
  static bool getTest() { return test; };
private:
  static uint32_t calculateCRC32(const uint8_t *data, size_t length);
  static bool readData();
  static void updateData();

};


#endif