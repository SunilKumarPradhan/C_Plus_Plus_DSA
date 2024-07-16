from visualiser.visualiser import Visualiser as vs

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

@vs(node_properties_kwargs={"shape": "record", "color": "#f57542", "style": "filled", "fillcolor": "grey"})
def inorder(root):
    if root is not None:
        inorder(root.left)
        print(root.key, end=' ')
        inorder(root.right)

def create_sample_tree():
    root = Node(3)
    root.left = Node(2)
    root.right = Node(4)
    root.right.right = Node(5)
    root.left.left = Node(1)
    return root



def main():
    root = create_sample_tree()
    print("InOrder Traversal:")
    inorder(root)
    print()  # For a newline after traversal output
    vs.make_animation("inorder_traversal.gif", delay=5)

if __name__ == "__main__":
    main()
