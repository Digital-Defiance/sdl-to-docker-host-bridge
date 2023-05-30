from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from fastapi.responses import HTMLResponse

app = FastAPI()

@app.get("/")
async def get_index():
    
    headers = {
        "Content-Type": "text/html",
        "Content-Security-Policy": "default-src 'self' ws://localhost:8888",
    }
    
    return HTMLResponse(content=open("index.html").read(), status_code=200)




