import java.util.*;

class Node {
  int data;
  Node next;
  Node previous;

  Node(int d, Node n, Node p) {
    this.data = d;
    this.next = n;
    this.previous = p;
  }

  Node(int d) {
    this(d, null, null);
  }
}

public class DoublyLinkedList {
  private static Node createDLL(ArrayList<Integer> arr) {
    Node head = new Node(arr.get(0));
    Node prev = head;
    for (int i = 1; i < arr.size(); i++) {
      Node temp = new Node(arr.get(i), null, prev);
      prev.next = temp;
      prev = temp;
    }
    return head;
  }

  private static void printDLL(Node head) {
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.data + " ");
      temp = temp.next;
    }
  }

  private static Node deleteHead(Node head) {
    if (head == null || head.next == null) {
      return null;
    }
    Node prev = head;
    head = head.next;

    head.previous = null;
    prev.next = null;

    return head;
  }

  private static Node deleteTail(Node head) {
    if (head == null || head.next == null) {
      return null;
    }

    Node temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }

    Node prev = temp.previous;
    prev.next = null;
    temp.previous = null;

    return head;
  }

  private static Node deleteKthNode(Node head, int k) {
    int count = 0;
    Node temp = head;
    while (temp != null) {
      count++;
      if (count == k)
        break;
      temp = temp.next;
    }
    System.out.println(temp.data);

    Node prev = temp.previous;
    Node next = temp.next;

    if (prev == null && next == null) {
      return null;
    } else if (prev == null) {
      return deleteHead(head);
    } else if (next == null) {
      return deleteTail(head);
    } else {
      prev.next = next;
      next.previous = prev;
      return head;
    }
  }

  private static void deleteNode(Node node) {
    Node prev = node.previous;
    Node next = node.next;

    if (next == null) {
      prev.next = null;
      node.previous = null;
    }

    prev.next = next;
    next.previous = prev;
  }

  private static Node insertBeforeHead(Node head, int val) {
    Node newHead = new Node(val, head, null);
    head.previous = newHead;
    head = newHead;
    return head;
  }

  private static void insertAfterHead(Node head, int val) {
    Node newNode = new Node(val, head.next, head);
    head.next = newNode;
    newNode.next.previous = newNode;
  }

  private static void insertAfterTail(Node head, int val) {
    Node temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }
    Node newTail = new Node(val, null, temp);
    temp.next = newTail;
  }

  private static void insertBeforeTail(Node head, int val) {
    Node temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }
    Node newNode = new Node(val, temp, temp.previous);
    temp.previous = newNode;
    newNode.previous.next = newNode;
  }

  private static void insertAfterKth(Node head, int val, int k) {
    int count = 0;
    Node temp = head;
    while (temp.next != null) {
      count++;
      if (count == k)
        break;
      temp = temp.next;
    }
    Node next = temp.next;
    Node newNode = new Node(val, next, temp);
    temp.next = newNode;
    next.previous = newNode;
  }

  private static void insertBeforeKth(Node head, int val, int k) {
    int count = 0;
    Node temp = head;
    while (temp.next != null) {
      count++;
      if (count == k)
        break;
      temp = temp.next;
    }
    Node prev = temp.previous;
    Node newNode = new Node(val, temp, prev);
    temp.previous = newNode;
    prev.next = newNode;
  }

  private static void insertAfterNode(Node node, int val) {
    Node next = node.next;
    Node newNode = new Node(val, next, node);
    next.previous = newNode;
    node.next = newNode;
  }

  private static void insertBeforeNode(Node node, int val) {
    Node prev = node.previous;
    Node newNode = new Node(val, node, prev);
    prev.next = newNode;
    node.previous = newNode;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    ArrayList<Integer> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(scanner.nextInt());
    }
    scanner.close();

    Node head = createDLL(arr);
    // head = deleteKthNode(head, 15);
    // deleteNode(head.next.next.next);
    // head = insertBeforeHead(head, 69);
    // insertBeforeKth(head, 100, 7);
    insertAfterNode(head.next.next.next.next.next, 1000);
    printDLL(head);
  }
}
