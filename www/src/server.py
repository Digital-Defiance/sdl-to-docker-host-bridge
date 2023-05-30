from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from fastapi.responses import HTMLResponse

app = FastAPI()

@app.get("/")
async def get_index():
    return HTMLResponse(content=open("index.html").read(), status_code=200)

