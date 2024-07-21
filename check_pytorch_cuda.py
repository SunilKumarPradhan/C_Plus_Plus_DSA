import torch

def check_pytorch_and_cuda():
    # Check PyTorch installation
    print(f"PyTorch version: {torch.__version__}")

    # Check if CUDA is available
    cuda_available = torch.cuda.is_available()
    print(f"CUDA available: {cuda_available}")

    if cuda_available:
        # Get the number of GPUs available
        num_gpus = torch.cuda.device_count()
        print(f"Number of GPUs: {num_gpus}")

        for i in range(num_gpus):
            # Get the name of the GPU
            gpu_name = torch.cuda.get_device_name(i)
            # Get the capability of the GPU
            gpu_capability = torch.cuda.get_device_capability(i)
            print(f"GPU {i}: {gpu_name}")
            print(f"  CUDA Capability: {gpu_capability}")
    else:
        print("CUDA is not available. Please check your installation and make sure your GPU supports CUDA.")

if __name__ == "__main__":
    check_pytorch_and_cuda()
