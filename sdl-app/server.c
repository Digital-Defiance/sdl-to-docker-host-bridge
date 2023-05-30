#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>

// WebSocket server callback
int callback_echo(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            printf("Client connected\n");
            break;
        case LWS_CALLBACK_RECEIVE:
            // Echo back the received message to the client
            lws_write(wsi, in, len, LWS_WRITE_TEXT);
            break;
        case LWS_CALLBACK_CLOSED:
            printf("Client disconnected\n");
            break;
        default:
            break;
    }

    return 0;
}

// WebSocket server protocol
static struct lws_protocols protocols[] = {
    {"echo-protocol", callback_echo, 0, 1024, 0, NULL, 0},
    {NULL, NULL, 0, 0, 0, NULL, 0}
};

int main() {
    // Create libwebsockets context
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));
    info.port = 8888;
    info.protocols = protocols;

    struct lws_context *context = lws_create_context(&info);
    if (context == NULL) {
        printf("Failed to create libwebsockets context\n");
        return -1;
    }

    // Run the libwebsockets event loop
    while (1) {
        lws_service(context, 0);
    }

    // Cleanup
    lws_context_destroy(context);

    return 0;
}
