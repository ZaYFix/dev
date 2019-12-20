#!/bin/bash
mv $HOME/Téléchargements/libDoxygen-0.4.6-qtc4.7.x-x86_64.so /tmp
sudo mv /tmp/libDoxygen-0.4.6-qtc4.7.x-x86_64.so /opt/Qt5.11.2/Tools/QtCreator/lib/qtcreator/plugins/
sudo chown root:root /opt/Qt5.11.2/Tools/QtCreator/lib/qtcreator/plugins/libDoxygen-0.4.6-qtc4.7.x-x86_64.so
sudo chmod 775 /opt/Qt5.11.2/Tools/QtCreator/lib/qtcreator/plugins/libDoxygen-0.4.6-qtc4.7.x-x86_64.so
