#include "handwrittenwrapper.h"


std::once_flag HandWrittenWrapper::instFlag_;
HandWrittenWrapper* HandWrittenWrapper::instance_ = nullptr;

HandWrittenWrapper::HandWrittenWrapper()
{}

HandWrittenWrapper* HandWrittenWrapper::instance() {
    std::call_once(
        HandWrittenWrapper::instFlag_,
        [](){ HandWrittenWrapper::instance_ = new HandWrittenWrapper(); }
    );
    return HandWrittenWrapper::instance_;
}

int HandWrittenWrapper::singleRecognize(const std::string& userImgPath,int &outLabel, 
                                        int& contentCode, std::string& contentName, int expectLabel) {
    //根据实际情况实现
    return -1;
}