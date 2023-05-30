FROM python:3.11


RUN pip install fastapi
RUN pip install uvicorn

WORKDIR /app

COPY ./src .


CMD ["uvicorn", "server:app", "--host", "0.0.0.0", "--port", "80", "--workers", "1"]
