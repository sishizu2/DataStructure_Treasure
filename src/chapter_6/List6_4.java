package chapter_6;

public class List6_4 {

	private static class aTreeNode{
		public int value;
		public aTreeNode left;
		public aTreeNode right;
	}

	private static aTreeNode treeRoot = null;

	private static aTreeNode createNewNode(int num) {
		aTreeNode newTree = new aTreeNode();
		newTree.value = num;
		newTree.left = null;
		newTree.right = null;
		return newTree;
	}

	private static void insertTree(int num, aTreeNode node) {

		// 1つも挿入されていない
		if(node == null) {
			treeRoot = createNewNode(num);
			return;
		}

		// num < 現在の値→左側に格納　小←　→大
		if(num < node.value) {
			if(node.left != null) {
				insertTree(num, node.left);
			}else {
				// 左側に追加
				node.left = createNewNode(num);
			}
		}else {
			// 現在のノードの値 < num		同じ値を追加した場合？？
			if(node.right != null) {
				insertTree(num, node.right);

			}else {
				// 右側に追加する
				node.right = createNewNode(num);
			}
		}
		return;

	}

	private static aTreeNode findValue(aTreeNode node, int val) {
		if(val < node.value) {
			// 現在のノードの値よりも小さければ、左側
			if(node.left == null) {
				// もし左側になければ、valはない
				return null;
			}
			// 左側にノードがあれば、探索継続
			return findValue(node.left, val);
		}
		if(node.value < val) {
			// 現在のノードよりも大きければ、右側
			if(node.right == null) {
				// もし右側にノードが無ければ、valは存在しない
				return null;
			}
			// 右側にノードがあれば、探索継続
			return findValue(node.right, val);
		}
		// val == node.valueの場合は、見つかった値を持つノードを返す
		return node;

	}

	private static boolean deleteTree(int val) {
		aTreeNode node = treeRoot;
		aTreeNode parentNode = null;
		int direction = 0;

		// while文で削除すべき対象を見つける(=find_value)
		// 現在ノードが存在し、数値がvalと異なる限り、探索実行
		while(node != null && node.value != val) {
			if(val < node.value) {
				parentNode = node;
				node = node.left;
				direction = -1;		// 左方向は-1
			}else {
				parentNode = node;
				node = node.right;
				direction = 1;		// 右方向は1
			}

		}

		if(node == null) {
			// 見つからなかった
			return false;
		}
		if(node.left == null || node.right == null) {
			// 左右いずれかのノードがNULLの場合
			if(node.left == null) {
				// 親のポインタを変更する
				if(direction == -1) {
					parentNode.left = node.right;
				}else if(direction == 1) {
					parentNode.right = node.right;
				}else if(direction == 0) {
					treeRoot = node.right;
				}
			}
		}
		return true;

































	}



}
