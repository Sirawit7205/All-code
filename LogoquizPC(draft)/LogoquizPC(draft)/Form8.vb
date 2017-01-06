Public Class Form8

    Private Sub Form8_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        TextBox1.Text = My.Settings.correct
        TextBox2.Text = My.Settings.score
        TextBox3.Text = My.Settings.hint
    End Sub
    Private Sub Button4_Click(sender As System.Object, e As System.EventArgs) Handles Button4.Click
        Close()
        Form1.Show()
    End Sub

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Dim i As Integer = 0
        If SaveFileDialog1.ShowDialog() = Windows.Forms.DialogResult.OK Then
            If My.Computer.FileSystem.FileExists(SaveFileDialog1.FileName) = True Then
                My.Computer.FileSystem.DeleteFile(SaveFileDialog1.FileName)
            End If
            Dim Wrt As New System.IO.StreamWriter(SaveFileDialog1.FileName, True)
            Wrt.WriteLine("1.0")
            Wrt.WriteLine(My.Settings.correct)
            Wrt.WriteLine(My.Settings.score)
            Wrt.WriteLine(My.Settings.hint)
            Wrt.WriteLine(My.Settings.lv1)
            Wrt.WriteLine(My.Settings.lv2)
            Wrt.WriteLine(My.Settings.lv3)
            Wrt.WriteLine(My.Settings.lv4)
            Wrt.WriteLine(My.Settings.lv5)
            Wrt.WriteLine(My.Settings.hint_plus)
            Wrt.Close()
            Do Until i > 149
                Dim W As New System.IO.StreamWriter(SaveFileDialog1.FileName, True)
                W.WriteLine(My.Settings.correction(i))
                W.Close()
                i += 1
            Loop
            i = 0
            Do Until i > 149
                Dim W As New System.IO.StreamWriter(SaveFileDialog1.FileName, True)
                W.WriteLine(My.Settings.HintUse(i))
                W.Close()
                i += 1
            Loop
            i = 0
            Do Until i > 149
                Dim w As New System.IO.StreamWriter(SaveFileDialog1.FileName, True)
                w.WriteLine(My.Settings.scr_cur(i))
                w.Close()
                i += 1
            Loop
        End If
        Label12.Visible = True
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Dim i As Integer = 0
        If OpenFileDialog1.ShowDialog() = Windows.Forms.DialogResult.OK Then
            Dim R As New System.IO.StreamReader(OpenFileDialog1.FileName, System.Text.Encoding.Default)
            If R.ReadLine() = "1.0" Then
                TextBox4.Text = R.ReadLine()
                TextBox5.Text = R.ReadLine()
                TextBox6.Text = R.ReadLine()
            Else
                MessageBox.Show("Invalid save file or wrong version save file.")
            End If
        End If
    End Sub

    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        Dim i As Integer = 0
        Dim temp As Integer = 0
        Dim dump As Integer = 0
        Dim R As New System.IO.StreamReader(OpenFileDialog1.FileName, System.Text.Encoding.Default)
        dump = R.ReadLine()
        My.Settings.correct = R.ReadLine()
        My.Settings.score = R.ReadLine()
        My.Settings.hint = R.ReadLine()
        My.Settings.lv1 = R.ReadLine()
        My.Settings.lv2 = R.ReadLine()
        My.Settings.lv3 = R.ReadLine()
        My.Settings.lv4 = R.ReadLine()
        My.Settings.lv5 = R.ReadLine()
        My.Settings.hint_plus = R.ReadLine()
        Do Until i > 149
            My.Settings.correction(i) = R.ReadLine()
            i += 1
        Loop
        i = 0
        Do Until i > 149
            My.Settings.HintUse(i) = R.ReadLine()
            i += 1
        Loop
        i = 0
        Do Until i > 149
            My.Settings.scr_cur(i) = R.ReadLine()
            i += 1
        Loop
        Label13.Visible = True
    End Sub
End Class