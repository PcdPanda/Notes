# Stable Diffusion
```sh
git clone https://github.com/AUTOMATIC1111/stable-diffusion-webui.git # 下载sd repo
conda env create -f environment-wsl2.yaml -n sd # 创建anaconda环境
cd stable-diffusion-webui && mkdir repositories
# 下载必要repo到目录中
git clone https://github.com/CompVis/stable-diffusion.git repositories/stable-diffusion
git clone https://github.com/CompVis/taming-transformers.git repositories/taming-transformers
git clone https://github.com/sczhou/CodeFormer.git repositories/CodeFormer
git clone https://github.com/salesforce/BLIP.git repositories/BLIP
# 安装必要Python包
pip install transformers diffusers invisible-watermark --prefer-binary
pip install git+https://github.com/crowsonkb/k-diffusion.git --prefer-binary
pip install git+https://github.com/TencentARC/GFPGAN.git --prefer-binary
pip install -r repositories/CodeFormer/requirements.txt --prefer-binary
pip install -r requirements.txt --prefer-binary
pip install -U numpy --prefer-binary
pip install xformers
pip install opencv-python-headless
# 下载模型并设置环境变量
cd /models/Stable-diffusion
wget https://huggingface.co/CompVis/stable-diffusion-v-1-4-original/resolve/main/sd-v1-4.ckpt
echo 'export LD_LIBRARY_PATH=/usr/lib/wsl/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
# 启动
source ~/.bashrc
conda activate sd
python launch.py --skip-version-check
```