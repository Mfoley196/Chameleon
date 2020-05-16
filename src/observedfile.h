/* Copyright 2020 Damien Masson, Sylvain Malacria, Edward Lank, Géry Casiez
               (University of Waterloo, Université de Lille, Inria, France)

This file is part of Chameleon.

Chameleon is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Chameleon is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Chameleon.  If not, see <https://www.gnu.org/licenses/>. */
#ifndef OBSERVEDFILE_H
#define OBSERVEDFILE_H

#include <QString>
#include <QFile>

class ObservedFile
{
public:
    ObservedFile(QString filePath);
    ObservedFile(ObservedFile& file);
    bool operator==(const ObservedFile &other) const;
    QString getPath() const;
    bool isDifferent();
    QString getMD5();
    qint64 getSize();

    int rememberedDecision;

private:
    QString path;
    QString cachedMD5;
    qint64 cachedSize;
    QString getMD5(QFile& file);

};

inline uint qHash(const ObservedFile &key, uint seed) {
    return qHash(key.getPath(), seed);
}

#endif // OBSERVEDFILE_H
