#ifndef TREESUB_H
#define TREESUB_H

#include <QTreeView>

class TreeSub : public QTreeView {
  Q_OBJECT
public:
  explicit TreeSub(QWidget *parent = nullptr);

Q_SIGNALS:
  void emitEmulateDataByClick(const QModelIndex &index);

protected:
  virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // TREESUB_H
