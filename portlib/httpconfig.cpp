#include "httpconfig.h"

#include <ctime>
#include <map>

//测试环境
const std::string TEST_URL = "";
//准生产环境域名
const std::string PRERELEASE_URL = "";
//生产环境域名
const std::string RELEASE_URL = "";

const std::string TEST_UPGRADE_URL = "";
const std::string RELEASE_UPGRADE_URL = "";

const std::string TEST_ALY_KEY_BASE = "";
const std::string PRERELEASE_ALY_KEY_BASE = "";
const std::string RELEASE_ALY_KEY_BASE = "";

const std::string UPGRADE_FORMAT = "";

enum class PlatformApiType {
    kUploadSign = 0,
    kPractiseUploadPc,
    kWorkCommitPc,
    kEduBookInfoDetail,
    kCourseContentDetail,
    kFileComponent,
    kDownload,
    kWorkPcCreate,
    kWorkPcFinish,
    kDictateUploadPc
};

std::map<PlatformApiType,std::string> platformApis {
    {PlatformApiType::kUploadSign,""},
    {PlatformApiType::kPractiseUploadPc,""},
    {PlatformApiType::kWorkCommitPc,""},
    {PlatformApiType::kEduBookInfoDetail,""},
    {PlatformApiType::kFileComponent,""},
    {PlatformApiType::kDownload,""},
    {PlatformApiType::kWorkPcCreate,""},
    {PlatformApiType::kWorkPcFinish,""},
    {PlatformApiType::kDictateUploadPc,""}
};

HttpConfig::HttpConfig()
    : envType_(Env::release)
    , baseUrl_(RELEASE_URL) 
{
}

void HttpConfig::setEnv(Env type) {
    envType_ = type;
    switch(envType_) {
        case Env::test:
            baseUrl_ = TEST_URL;
            break;
        case Env::prerelease:
            baseUrl_ = PRERELEASE_URL;
            break;
        case Env::release:
            baseUrl_ = RELEASE_URL;
            break;
    }
}

HttpConfig *HttpConfig::instance()
{
    static HttpConfig* i = new HttpConfig();
    return i;
}

std::string HttpConfig::getUpdataFile()
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kUploadSign];
    return url;
}

std::string HttpConfig::getEvaluateResult()
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kPractiseUploadPc];
    return url;
}

std::string HttpConfig::getWorkCommit()
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kWorkCommitPc];
    return url;
}

std::string HttpConfig::getBookInfoDetail(int pageId)
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kEduBookInfoDetail];
    url.append("?");
    url.append("id=B");
    if(pageId/1000 > 0){

    }else if(pageId/100 > 0){
        url.append("0");
    }else if(pageId/10 > 0){
        url.append("00");
    }else {
        url.append("000");
    }
    url.append(std::to_string(pageId));
    return url;
}

std::string HttpConfig::getAlyKeyBasePath()
{
    std::string keyBase;
    switch(envType_) {
        case Env::test:
            keyBase = TEST_ALY_KEY_BASE;
            break;
        case Env::prerelease:
            keyBase = PRERELEASE_ALY_KEY_BASE;
            break;
        case Env::release:
            keyBase = RELEASE_ALY_KEY_BASE;
            break;
    }
    return keyBase;
}

std::string HttpConfig::getSideXmlUrl()
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kFileComponent];
    url.append(std::to_string(time(nullptr)));
    return url;
}

std::string HttpConfig::getDownloadUrl(const std::string& urls, int validTime)
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kDownload];
    url.append("?urls="+urls);
    url.append("&validTime="+std::to_string(validTime));
    return url;
}

std::string HttpConfig::getUpgradeUrl(const std::string& moduleName, const std::string& productName,const std::string& version)
{
    std::string url;
    if(envType_ == Env::test || envType_ == Env::prerelease){
       url = TEST_UPGRADE_URL;
    } else {
       url = RELEASE_UPGRADE_URL;
    }
    char buf[1024]{0};
    sprintf(buf,UPGRADE_FORMAT.c_str(),moduleName.c_str(),productName.c_str(),version.c_str());
    url += buf;
    return url;
}

std::string HttpConfig::getCreateWorkClassUrl(int lessonId, int classId)
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kWorkPcCreate];
    url.append(std::to_string(lessonId)+"/"+std::to_string(classId));
    return url;
}

std::string HttpConfig::getFinishAllWorkClassUrl()
{
    std::string url = baseUrl_ + platformApis[PlatformApiType::kWorkPcFinish];
    return url;
}

std::string HttpConfig::getDictationResult()
{
   std::string url = baseUrl_ + platformApis[PlatformApiType::kDictateUploadPc];
   return url;
}
