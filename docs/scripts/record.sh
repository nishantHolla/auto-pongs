#!/bin/bash

APP_NAME="Auto Pong"
DURATION=10
FPS=60
VIDEO_OUT="2_pong.mp4"
GIF_OUT="2_pong.gif"

WIN_ID=$(xdotool search --name "$APP_NAME" | head -n 1)
if [ -z "$WIN_ID" ]; then
  echo "Could not find window with name: $APP_NAME"
  exit 1
fi

GEOM=$(xdotool getwindowgeometry --shell $WIN_ID)
eval $GEOM

echo "Recording $APP_NAME at ${WIDTH}x${HEIGHT}+${X},${Y} for $DURATION seconds..."

ffmpeg -y -video_size ${WIDTH}x${HEIGHT} -framerate $FPS \
    -f x11grab -i :0.0+${X},${Y} -t $DURATION $VIDEO_OUT

ffmpeg -y -i $VIDEO_OUT -vf "fps=15,scale=640:-1:flags=lanczos" $GIF_OUT

echo "Saved $VIDEO_OUT and $GIF_OUT"

