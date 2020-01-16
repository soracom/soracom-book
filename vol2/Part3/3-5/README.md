# 第 3 部 IoT システム開発をハンズオン解説

## 第 5 章 デバイスの遠隔操作

### 5-5 STEP4 SORACOM Napter を使ったリモートデスクトップ接続

```console
sudo apt update && sudo apt install -y raspberrypi-ui-mods
sudo reboot
```

#### 5-5-1 VNC Server 設定

```
sudo sed -e 's/^\#framebuffer_/framebuffer_/' /boot/config.txt -ibak
```

#### 5-5-2 VNC Viewer 設定

- RealVNC: https://www.realvnc.com/en/connect/download/viewer/
