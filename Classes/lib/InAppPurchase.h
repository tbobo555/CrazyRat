#ifndef _Lib_InAppPurchase_H_
#define _Lib_InAppPurchase_H_

#include "cocos2d.h"
#include "PluginIAP/PluginIAP.h"

class InAppPurchase : public sdkbox::IAPListener
{
public:
    InAppPurchase();
private:
    virtual void onInitialized(bool ok) override;
    virtual void onSuccess(sdkbox::Product const& p) override;
    virtual void onFailure(sdkbox::Product const& p, const std::string &msg) override;
    virtual void onCanceled(sdkbox::Product const& p) override;
    virtual void onRestored(sdkbox::Product const& p) override;
    virtual void onProductRequestSuccess(std::vector<sdkbox::Product> const &products) override;
    virtual void onProductRequestFailure(const std::string &msg) override;
    void onRestoreComplete(bool ok, const std::string &msg);
};

#endif /* _Lib_InAppPurchase_H_ */
