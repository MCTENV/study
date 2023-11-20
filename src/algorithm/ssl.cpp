
// 导入openssl
#include <openssl/ssl.h>
#include <openssl/err.h>

// 新建ssl ctx且支持双向认证，所有信息在/home/juxuhua/info下
SSL_CTX* createSSLContext() {
    SSL_CTX* ctx = SSL_CTX_new(SSLv23_method());
    if (!ctx) {
        // 处理创建ctx失败的情况
        return nullptr;
    }
    
    // 加载CA证书
    if (SSL_CTX_load_verify_locations(ctx, "/home/juxuhua/info/ca.crt", nullptr) != 1) {
        // 处理加载CA证书失败的情况
        SSL_CTX_free(ctx);
        return nullptr;
    }
    
    // 加载服务器证书
    if (SSL_CTX_use_certificate_file(ctx, "/home/juxuhua/info/server.crt", SSL_FILETYPE_PEM) != 1) {
        // 处理加载服务器证书失败的情况
        SSL_CTX_free(ctx);
        return nullptr;
    }
    
    // 加载服务器私钥
    if (SSL_CTX_use_PrivateKey_file(ctx, "/home/juxuhua/info/server.key", SSL_FILETYPE_PEM) != 1) {
        // 处理加载服务器私钥失败的情况
        SSL_CTX_free(ctx);
        return nullptr;
    }
    
    // 验证服务器私钥是否正确
    if (SSL_CTX_check_private_key(ctx) != 1) {
        // 处理服务器私钥验证失败的情况
        SSL_CTX_free(ctx);
        return nullptr;
    }
    
    // 设置双向认证
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, nullptr);
    
    return ctx;
}

