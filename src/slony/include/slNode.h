//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// slNode.h PostgreSQL Slony-I Node
//
//////////////////////////////////////////////////////////////////////////

#ifndef SLNODE_H
#define SLNODE_H

// wxWindows headers
#include <wx/wx.h>

// App headers
#include "pgAdmin3.h"
#include "pgObject.h"
#include "pgServer.h"
#include "pgDatabase.h"
#include "slObject.h"


class slNode : public slObject
{
public:
    slNode(slCluster *_cluster, const wxString& newName = wxT(""));
    ~slNode();

    int GetIcon() { return SLICON_NODE; }
    void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
    static void ShowStatistics(slCollection *collection, ctlListView *statistics);
    void ShowStatistics(frmMain *form, ctlListView *statistics);
    static pgObject *ReadObjects(slCollection *coll, wxTreeCtrl *browser, const wxString &restriction);
    static pgObject *ReadObjects(slCollection *coll, wxTreeCtrl *browser);

//    bool CanBackup() { return true; }
    bool RequireDropConfirm() { return true; }
    bool WantDummyChild() { return true; }

    bool GetActive() const { return active; }
    void iSetActive(bool b) { active=b; }
    wxString GetConnInfo() const {return connInfo; }
    void iSetConnInfo(const wxString s) { connInfo = s; }
    long GetPid() { return pid; }

    bool DropObject(wxFrame *frame, wxTreeCtrl *browser);
    wxMenu *GetNewMenu();
    wxString GetSql(wxTreeCtrl *browser);
    pgObject *Refresh(wxTreeCtrl *browser, const wxTreeItemId item);

private:
    bool active;
    long pid;
    wxString connInfo;
};

#endif

