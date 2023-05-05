#include "charevaluationwrapper.h"

std::once_flag CharEvaluationWrapper::instFlag_;
CharEvaluationWrapper* CharEvaluationWrapper::instance_ = nullptr;

CharEvaluationWrapper* CharEvaluationWrapper::instance() {
    std::call_once(
        CharEvaluationWrapper::instFlag_,
        [](){ CharEvaluationWrapper::instance_ = new CharEvaluationWrapper(); }
    );
    return CharEvaluationWrapper::instance_;
}

bool CharEvaluationWrapper::wordEvaluate(EvaluationRequest& request, EvaluateReportBody& body) {
    //替换为实际代码
    return false;
}