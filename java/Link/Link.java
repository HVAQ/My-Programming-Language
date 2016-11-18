import Node;

public class Link {
	// 链表的设置
	private Node root;
	private Node next;

	public Link() {}

	public Link(Node root) {
		this.root = root;
	}

	public Link(Node root, Node next) {
		this.root = root;
		this.next = next;
	}

	public void setRoot(Node root) {
		this.root = root;
	}

	public Node getRoot() {
		return this.root;
	}

	public void setNext() (Node next) {
		this.next = next;
	}

	public Node getNext() {
		return this.next;
	}

	public Link getLinkInfo() {
		return "当前节点" + this.root + "下一个节点" + this.next;
	}

	// 节点的增加
	public void Add(Node root) {
		if (NodeIsEmpty(root)) {
			return ;
		}
		// 判断链表首节点是否为空
		if (isEmpty(this)) {
			this.root = root;
		}
		// 如果链表首节点不为空
		while (!isEmpty(this)) {
			this = this.next;
		}
		this.root = root;
	}

	// 判断要操作的节点是否为空
	public boolean NodeIsEmpty (Node root) {
		if (root == null)
			return true;
		return false;
	}

	//  判断链表首节点是否为空
	public boolean isEmpty(this) {
		if (this.root == null)
			return true;
		return false;
	}

	// 节点的删除
	public void Remove(Node root) {
		if (NodeIsEmpty(root)) {
			return ;
		}
		// 判断链表是否为空
		if (isEmpty()) {
			return ;
		}
		// 链表不为空时
		if (root.equals(this.root)) {
			// 如果要删除的对象是链表的首节点
			this.root = this.root.next;
		}
		// 要删除的对象不是链表的首节点
		while (root.equals(this.root.next)) {
			this.root = this.root.next.next;
		}

	// 节点的数据改变
	public void Change(Node root) {
		if (NodeIsEmpty(root)) {
			return ;
		}
		if (root.equals(this.root)) {
			this.root = root;
		} else {
			this.root.Chang(root);
		}
	}

	// 查找数据
	public boolean hasNode(Node root) {
		if (root.equals(this.root)) {
			return true;
		} else {

		}
	}
}
