from visualiser.visualiser import Visualiser as vs

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

@vs(node_properties_kwargs={"shape": "record", "color": "#f57542", "style": "filled", "fillcolor": "grey"})
def height(root):
    if root is None:
        return 0
    else:
        return max(height(root.left), height(root.right)) + 1

def create_sample_tree():
    root = Node(3)
    root.left = Node(2)
    root.right = Node(4)
    root.right.right = Node(5)
    root.left.left = Node(1)
    return root

def main():
    root = create_sample_tree()
    print("The height of this binary tree is:")
    print(height(root))
    vs.make_animation("tree_height.gif", delay=1)

if __name__ == "__main__":
    main()
