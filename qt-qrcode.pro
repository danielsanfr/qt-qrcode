TEMPLATE = subdirs

SUBDIRS += \
    widget \
    quickitem \
    lib

widget.depends = lib
quickitem.depends = lib
