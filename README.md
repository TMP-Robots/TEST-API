# TEST-API

This example is used as the development playground for the `TMP-API` library — 
we use it to develop and test the API.

**Overview:** The `TEST-API` example demonstrates how to use `TMP-API` to create
 a small HTTP-based robot server on an ESP32-S3. The example exposes a few 
 runtime variables (RGB color and brightness) through the API and shows how to 
 enable OTA updates.

**What the example does:**
- Starts a `TMP_RobotServer` on port 80.
- Connects to Wi‑Fi using credentials from `config/secrets.ini`.
- Enables OTA uploads protected by an `OTA_PASSWORD`.
- Registers variables `red`, `green`, `blue`, and `brightness` which are 
  writable via the API.
- Drives a single NeoPixel LED using the registered variables in the main loop.

**Key files in TEST-API:**
- `src/main.cpp` — Shows how to initialize `TMP_RobotServer`, register variables, 
  enable OTA, and update the NeoPixel.
- `platformio.ini` — Project configuration and build environments (USB and OTA). 
  It references this library via a local symlink dependency: `symlink://../TMP-API`.
- `config/secrets.ini.dist` — Template for required secrets (Wi‑Fi SSID, Wi‑Fi 
  password, and `ota_upload_password`). Copy this to `config/secrets.ini` and 
  fill in real values before building.

**Variables exposed by the example**
- `red` (0-255): red channel value
- `green` (0-255): green channel value
- `blue` (0-255): blue channel value
- `brightness` (0-255): global LED brightness

These variables are registered in `main.cpp` and will be exposed by the `TMP-API` 
server. The implementation exposes them over HTTP so they can be read and updated 
remotely (see `TEST-API` code for exact endpoints and UI if provided).

**How to run the example (PlatformIO):**
1. Copy the secrets template and fill your credentials:

	cp TEST-API/config/secrets.ini.dist TEST-API/config/secrets.ini

	Edit `TEST-API/config/secrets.ini` and set `wifi_ssid`, `wifi_password`, and 
	`ota_upload_password`.

2. Build and upload over USB:

	platformio run -e esp32_s3_devkitc_1_usb -t upload

3. Or upload over OTA (device must be on the same network and `upload_port` set 
   in `platformio.ini`):

	platformio run -e esp32_s3_devkitc_1_ota -t upload

4. Use the debug environments to enable extra debug logging:

	platformio run -e debug_esp32_s3_devkitc_1_usb -t upload

---

See the [`TMP-API` repository](https://github.com/TMP-Robots/TMP-API) for more 
details on the API and how to use it in your own projects!